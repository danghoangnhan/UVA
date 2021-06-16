from os import listdir
from os.path import isfile, join
import os 
def cleanFolder(path):
    files = [f for f in listdir(path) if isfile(join(path, f))]

    for file in files:
        
        if file.endswith('.exe'):
            os.remove(file)
        if os.path.isdir(file):
            cleanFolder(path+file)



currentPath = os.path.dirname(os.path.realpath(__file__))
cleanFolder(currentPath)