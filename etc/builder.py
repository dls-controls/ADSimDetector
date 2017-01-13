import xml.dom.minidom
import os
import iocbuilder
from iocbuilder import Substitution, AutoSubstitution, SetSimulation, Device, records, Architecture, IocDataStream
from iocbuilder.arginfo import *
from iocbuilder.modules.asyn import Asyn, AsynPort, AsynIP
from iocbuilder.modules.busy import Busy
from iocbuilder.modules.calc import Calc
from iocbuilder.modules.ADBinaries import ADBinaries
from iocbuilder.modules.ADCore import ADCore, ADBaseTemplate, makeTemplateInstance, includesTemplates, NDDataTypes

__all__ = ['simDetector']

class simDetectorTemplate(AutoSubstitution):
    TemplateFile = "simDetector.template"

class simDetector(AsynPort):
    """Creates a simulation detector"""
    Dependencies = (ADCore,)
    # This tells xmlbuilder to use PORT instead of name as the row ID
    UniqueName = "PORT"
    _SpecificTemplate = simDetectorTemplate
    def __init__(self, PORT, WIDTH, HEIGHT, DATATYPE = 1, BUFFERS = 50, MEMORY = 0, **args):
        # Init the superclass (AsynPort)
        self.__super.__init__(PORT)
        # Update the attributes of self from the commandline args
        self.__dict__.update(locals())
        # Make an instance of our template
        makeTemplateInstance(self._SpecificTemplate, locals(), args)

    # __init__ arguments
    ArgInfo = ADBaseTemplate.ArgInfo + _SpecificTemplate.ArgInfo + makeArgInfo(__init__,
        PORT = Simple('Port name for the detector', str),
        WIDTH = Simple('Image Width', int),
        HEIGHT = Simple('Image Height', int),
        DATATYPE = Enum('Datatype', NDDataTypes),
        BUFFERS = Simple('Maximum number of NDArray buffers to be created for plugin callbacks', int),
        MEMORY = Simple('Max memory to allocate, should be maxw*maxh*nbuffer for driver and all attached plugins', int))

    # Device attributes
    LibFileList = ['simDetector']
    DbdFileList = ['simDetectorSupport']

    def Initialise(self):
        print '# simDetectorConfig(portName, maxSizeX, maxSizeY, dataType, maxBuffers, maxMemory)'
        print 'simDetectorConfig("%(PORT)s", %(WIDTH)s, %(HEIGHT)s, %(DATATYPE)d, %(BUFFERS)d, %(MEMORY)d)' % self.__dict__


