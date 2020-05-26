#!/usr/bin/env python3.4
import sys
import subprocess
import time

def usage():
    print("USAGE\n\t\t./launcher.py nb_ia team_name port [host]")
    sys.exit(-1)

lenght = len(sys.argv)
if (lenght < 4 or lenght > 5):
    usage()
else:
    nb_ia = int(sys.argv[1])
    team_name = sys.argv[2]
    port = sys.argv[3]
    if (lenght == 5):
        hostname = sys.argv[4]
    try:
        for i in range(nb_ia):
            time.sleep(1)
            if (lenght == 4):
                subprocess.Popen(["./zappy_ai", "-n", team_name, "-p", port])
            else:
                subprocess.Popen(["./zappy_ai", "-n", team_name, "-p", port, "-h", hostname])
    except KeyboardInterrupt:
        sys.exit(0)
