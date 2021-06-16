from os import listdir
from os.path import isfile, join
import os 
def cleanFolder(path):
    for root, directories, files in os.walk(path, topdown=False):
        for name in files:
            print(os.path.join(root, name))
            if name.endswith('.exe'):
                os.remove(os.path.join(root, name))
        for name in directories:
            print(os.path.join(root, name))



currentPath = os.path.dirname(os.path.realpath(__file__))
cleanFolder(currentPath)
