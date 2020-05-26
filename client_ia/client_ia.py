#!/usr/bin/env python3.4
import sys
sys.path.append("./client_ia")
import initclient as init
import selectclient as select
from Caracter import Caracter
import time

port = 0
tn = ""
hn = "127.0.0.1"

def error_syntax():
    print("USAGE\n\t\t./client_ia -n team name -p port -h hostname")
    sys.exit(-1);

def parse_line():
    global port
    global tn
    global hn
    nb_args = len(sys.argv)
    if (nb_args != 5 and nb_args != 7):
        error_syntax()
    else:
        for i in range(nb_args):
            try:
                if (sys.argv[i][0] == "-"):
                    if (sys.argv[i][1] == "p"):
                        port = int(sys.argv[i + 1])
                    elif (sys.argv[i][1] == "n"):
                        tn = sys.argv[i + 1]
                    elif (sys.argv[i][1] == "h"):
                        hn = sys.argv[i + 1]
            except (ValueError, IndexError):
                error_syntax()
        if (tn == "" or hn == 0 or port == 0 or tn == "GRAPHIC"):
            error_syntax()

if __name__ == '__main__':
    parse_line()
    print("port: {0:d}\tteam name: {1:s}\thostname: {2:s}".format(port, tn, hn))
    string = ""
    ia = Caracter(tn)
    sock = init.create_socket(int(port), hn)
    if (sock == -1):
        print("Failed")
    else:
        try:
            while True:
                string = select.select_sock(sock)
                if (string != 0):
                    ia.reception(string, sock)
                else:
                    ia.algo(sock)
        except KeyboardInterrupt:
            print("quit")
            sys.exit(0)
