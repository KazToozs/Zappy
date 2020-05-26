#!/usr/bin/env python3.4
from distutils.core import setup, Extension
import os, shutil

socket = Extension('initclient', sources = ['./client_ia/socket.c'])

setup (name = 'SocketPackage',
        version = '1.0',
        description = 'This is the Init Socket',
        ext_modules = [socket])

select = Extension('selectclient', sources = ['./client_ia/select.c'])

setup (name = 'SelectPackage',
        version = '1.0',
        description = 'This is the Select check',
        ext_modules = [select])

os.rename("./build/lib.linux-x86_64-3.4/initclient.cpython-34m.so", 
          "./client_ia/initclient.so")
os.rename("./build/lib.linux-x86_64-3.4/selectclient.cpython-34m.so", 
          "./client_ia/selectclient.so")
shutil.rmtree('build')
