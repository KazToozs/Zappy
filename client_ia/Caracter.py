import selectclient as select
import json
import time
import sys
from pprint import pprint

class Caracter:
    inventory = {
		"nourriture": "10",
		"linemate": "0",
		"deraumere": "0",
		"sibur": "0",
		"mendiane": "0",
		"phiras": "0",
		"thystame": "0" }
    userMax = 0
    viewNonBlocking = False
    addinventory = []
    rotation = 0
    lvl = 1
    init = False
    eggs = False
    walking = False
    waiting = True
    direction = 0
    broadcasting = 0
    incantatiting = False
    needFood = True
    nb_player = 1
    foodTaken = 0
    view = None
    lvljson = None
    needUpdate = False

    def printInfo(self):
        print("Team: ", self.team, "userMax: ", self.userMax, "nbplayer", self.nbplayer, "lvl: ", self.lvl, "eggs: ", self.eggs)

    def __init__(self, t):
        self.team = t

    def setNeedForUp(self, data):
        self.needForUp = data

    def reception(self, data, sock):
        if (data.find("mort") != -1):
            print("Je vais me coucher.")
            sys.exit(0)
        if (data == "BIENVENUE\n"):
            select.write_sock(sock, self.team + '\n')
            time.sleep(1)
            res = select.select_sock(sock).split("\n")
            try:
                self.userMax = int(res[0])
            except ValueError:
                self.userMax = -1
            try:
                with open('./client_ia/lvltab.json') as data_file:
                    self.lvljson = json.load(data_file)
            except FileNotFoundError:
                print("file not found")
            if (self.lvljson is not None):
                self.setNeedForUp(self.lvljson["tablvl"][0])
            else:
                str1 = '{"joueurs" : "1", "linemate" : "1", "deraumere" : "0",'
                str2 = '"sibur" : "0", "mendiane" : "0", "phiras" : "0", "thystame" : "0"}'
                j = json.loads(str1 + str2)
                self.setNeedForUp(j)
            self.waiting = False
        if (data.find("message") != -1 and data.find(self.team) != -1):
            tmp = data
            tab = tmp.split(" ")
            if (tab[2] == "present\n" and self.broadcasting > 0):
                self.broadcasting -= 1
                if (self.broadcasting == 0):
                    self.incantatiting = True
            elif (self.broadcasting == 0):
                try:
                    needlvl = int(tab[2])
                    nbneed = int(tab[3])
                except ValueError:
                    needlvl = self.lvl
                    nbneed = 1
                if (needlvl == self.lvl):
                    tmp = tab[1].split(",")
                    try:
                        self.direction = int(tmp[0])
                    except ValueError:
                        self.direction = -1
                    self.waiting = False
                    self.walking = True
                    if (nbneed == 0):
                        self.walking = False
                        self.incantatiting = False
                    elif (self.direction == 0):
                        self.walking = False
                        select.write_sock(sock, "broadcast toto present\n")
                        time.sleep(0.1)
                        select.write_sock(sock, "incantation\n")
                        self.incantatiting = True
        elif (data.find("{ joueur") != -1):
            data = data.replace("{", "")
            data = data.replace("}", "")
            data = data.replace("\n", "")
            tab = data.split(",")
            self.view = tab
            self.waiting = False
        elif(self.incantatiting == True):
            if(data.find("niveau") != -1):
                if (self.lvljson is not None):
                    self.setNeedForUp(self.lvljson["tablvl"][self.lvl])
                select.write_sock(sock, "voir\n")
                self.lvl += 1
                self.incantatiting = False
                self.broadcasting = 0
                self.needFood = True
                self.waiting = True
            elif(data == "ko\n"):
                print("incantaion Failed")
                self.incantatiting = False
                self.broadcasting = 0
                self.waiting = False
                self.needFood = True
        elif(self.init == False):
            if(data.find("ok") != -1):
                self.waiting = False

    def drawparcour(self, case):
        parcour = []
        value = 0
        if (case >= 1 and case <= 3):
            parcour.append("avance")
            value = case - 2
        elif (case >= 4 and case <= 8):
            for i in range(2):
                parcour.append("avance")
            value = case - 6
        if (value < 0):
            parcour.append("gauche")
            while (value < 0):
                parcour.append("avance")
                value += 1
        elif(value > 0):
            parcour.append("droite")
            while (value > 0):
                parcour.append("avance")
                value -= 1
        if (len(parcour) <= 6):
            return parcour
        return None

    def takeObject(self, sock, item):
        msg = "prend " + item + "\n"
        select.write_sock(sock, msg)
        self.inventory[item] = int(self.inventory[item]) + 1

    def leaveObject(self, sock, item):
        msg = "pose " + item + "\n"
        select.write_sock(sock, msg)
        self.inventory[item] = int(self.inventory[item]) - 1

    def getFood(self, sock):
        parcour = None
        for i in range(self.view[0].count("nourriture")):
            self.takeObject(sock, "nourriture")
            self.foodTaken += 1
        if(self.view[2].find("nourriture") != -1 and self.foodTaken <= 7):
            select.write_sock(sock, "avance\n")
        else:
            if (self.foodTaken > 7):
                self.foodTaken = 0
                self.rotation = 0
                self.needFood = False
            elif (self.rotation != 4):
                select.write_sock(sock, "droite\n")
                select.write_sock(sock, "voir\n")
                self.rotation += 1
                self.waiting = True
            elif (self.rotation == 4):
                select.write_sock(sock, "avance\n")
                select.write_sock(sock, "voir\n")
                self.rotation = 0
                self.waiting = True

    def need(self, sock):
        parcour = None
        taken = False
        self.needUpdate = False
        for i in self.needForUp:
            if (i != "joueurs"):
                if (self.needForUp[i] != "0" and self.needForUp[i] != self.inventory[i]):
                    if (self.view[0].find(i) != -1 and self.view[0].find("joueur") == -1):
                        self.takeObject(sock, i)
                        taken = True
                    else:
                        cmp = 0
                        for case in self.view:
                            if (case.find(i) != -1 and case.find("joueur") == -1):
                                parcour = self.drawparcour(cmp)
                            cmp += 1
                        if (parcour != None):
                            for move in parcour:
                                select.write_sock(sock, move + "\n")
                                time.sleep(0.5)
                            self.takeObject(sock, i)
                            self.needUpdate = True
                            taken = True
                            break
        if (self.needUpdate == True):
            select.write_sock(sock, "voir\n")
            self.waiting = True
        if (taken == False and parcour == None and self.rotation != 4):
            select.write_sock(sock, "droite\n")
            self.rotation += 1
            self.waiting = False
        elif (self.rotation == 4):
            select.write_sock(sock, "avance\n")
            self.rotation = 0
            self.waiting = False
        elif (taken == True):
            self.walking = False

    def checkCurrent(self):
        current = self.view[0].split(" ")
        for i in self.needForUp:
            if (i != "joueurs"):
                cpt = 0
                for item in current:
                    if (item == i):
                        cpt += 1
                if (cpt != int(self.needForUp[i])):
                    return False
        return True

    def incantation(self, sock):
        nb_player = 0
        for i in self.needForUp:
            current = self.view[0].split(" ")
            if (i != "joueurs"):
                cpt = 0
                for item in current:
                    if (item == i):
                        cpt += 1
                if (cpt != int(self.needForUp[i])):
                    if (cpt > int(self.needForUp[i])):
                        self.takeObject(sock, i)
                        self.waiting = True
                    elif(cpt < int(self.needForUp[i]) and int(self.inventory[i]) > 0):
                        self.leaveObject(sock, i)
                        self.waiting = True
        for item in current:
            if (item == "joueur"):
                nb_player += 1
        if (nb_player != int(self.needForUp["joueurs"])):
            needed = int(self.needForUp["joueurs"]) - nb_player
            self.waiting = False
            self.broadcasting = needed
            self.incantatiting = False
        else:
            select.write_sock(sock, "incantation\n")
            self.incantatiting = True
            self.waiting = True

    def checkNeed(self):
        for i in self.needForUp:
            if (i != "joueurs"):
                if (self.needForUp[i] != "0"):
                    if (int(self.needForUp[i]) > int(self.inventory[i])):
                        return True
        return False

    def walk(self, sock):
        self.viewNonBlocking = True
        if (self.direction == 0):
            select.write_sock(sock, "voir\n")
            self.waiting = True
            self.incantatiting = True
            self.viewNonBlocking = False
        elif (self.direction == 1):
            select.write_sock(sock, "avance\n")
        elif (self.direction > 1 and self.direction < 4):
            select.write_sock(sock, "gauche\n")
            select.write_sock(sock, "avance\n")
        elif (self.direction >= 4 and self.direction <= 6):
            select.write_sock(sock, "droite\n")
            select.write_sock(sock, "droite\n")
            select.write_sock(sock, "avance\n")
        elif (self.direction > 6 and self.direction < 9):
            select.write_sock(sock, "droite\n")
            select.write_sock(sock, "avance\n")
        self.waiting = True

    def algo(self, sock):
        if (self.waiting == False):
            if (self.init == False):
                if (self.userMax < 4 and self.eggs == False):
                    select.write_sock(sock, "fork\n")
                    self.eggs = True
                self.init = True
                self.waiting = True
            if (self.view == None):
                select.write_sock(sock, "voir\n")
                self.waiting = True
            elif(self.walking == True):
                self.walk(sock)
                self.waiting = True
            elif (self.incantatiting == False):
                self.viewNonBlocking = False
                if (self.needFood == True):
                    self.getFood(sock)
                elif (self.checkNeed() == True):
                    self.need(sock)
                else:
                    self.waiting = True
                    self.incantation(sock)
                self.view = None
            if(self.broadcasting > 0):
                self.incantatiting = True
                msg = "broadcast " + self.team + " " + str(self.lvl) + " " + str(self.broadcasting) + "\n"
                select.write_sock(sock, msg)
                time.sleep(2)
