var express = require('express');

var app = express();
var port = process.env.PORT || 1234;

var Connected = false;
var buffer = "";
var Maps = null
var TeamName = [];
var PlayerList = [];
var net = require('net');
var client = new net.Socket();
var Connected = false;
var sgtValue = 0;
var ConnectionArgs;

function msz_cmd(args) {
    Maps.sizeX = args[1];
    Maps.sizeY = args[2];
}
function bct_cmd(args) {
    if (Maps.Case[args[1]] == null) {
        Maps.Case[args[1]] = [];
    } 
    Maps.Case[args[1]][args[2]] = {posX: 0, posY: 0, Ressource: []};
    Maps.Case[args[1]][args[2]].posX = args[1];
    Maps.Case[args[1]][args[2]].posY = args[2];
    Maps.Case[args[1]][args[2]].Ressource[0] = args[3];
    Maps.Case[args[1]][args[2]].Ressource[1] = args[4];
    Maps.Case[args[1]][args[2]].Ressource[2] = args[5];
    Maps.Case[args[1]][args[2]].Ressource[3] = args[6];
    Maps.Case[args[1]][args[2]].Ressource[4] = args[7];
    Maps.Case[args[1]][args[2]].Ressource[5] = args[8];
    Maps.Case[args[1]][args[2]].Ressource[6] = args[9];
}
function tna_cmd(args) {
    TeamName[TeamName.length] = args[1];
}
function pnw_cmd(args) {
    var exist = false;
    for (var i = 0; i < PlayerList.length; i++) {
        if (PlayerList[i].id == args[1]) {
            exist = true;
            PlayerList[i] = {
                id: args[1],
                posX: args[2],
                poxY: args[3],
                Orientation: args[4],
                Level: args[5],
                TeamName: args[6],
                Ressource: [0,0,0,0,0,0,0]
            }
        }
    }
    if (exist == false) {
        PlayerList[i] = {
            id: args[1],
            posX: args[2],
            poxY: args[3],
            Orientation: args[4],
            Level: args[5],
            TeamName: args[6],
            Ressource: [0,0,0,0,0,0,0]
        }
    }
}
function ppo_cmd(args) {
    for (var i = 0; i < PlayerList.length; i++) {
        if (PlayerList[i].id == args[1]) {
            PlayerList[i].posX = args[2];
            PlayerList[i].posY = args[3];
            PlayerList[i].Orientation = args[4];
        }
    }
}
function plv_cmd(args) {
    for (var i = 0; i < PlayerList.length; i++) {
        if (PlayerList[i].id == args[1]) {
            PlayerList[i].Level = args[2];
        }
    }
}
function pdi_cmd(args) {
    console.log("Je suis ici");
    for (var i = 0; i < PlayerList.length; i++) {
        if (PlayerList[i].id == args[1]) {
            PlayerList.splice(i, 1);
            break;
        }
    }
}
function pin_cmd(args) {
    for (var i = 0; i < PlayerList.length; i++) {
        if (PlayerList[i].id == args[1]) {
            PlayerList[i].posX = args[2];
            PlayerList[i].posY = args[3];
            PlayerList[i].Ressource = [
                args[4],
                args[5],
                args[6],
                args[7],
                args[8],
                args[9],
                args[10]
            ];
        }
    }
}
function sgt_cmd(args) {
    sgtValue = args[1];
}
function ResetClient() {
    Maps = null
    TeamName = [];
}
function ExecLine(line, index) {
    var args = line.split(" ");
    switch (args[0]) {
        case "BIENVENUE" :
            Maps = {sizeX: 0, sizeY: 0, Case: []};
            client.write("GRAPHIC\n");
            client.write("sgt\n");
            break;
        case "msz" :
            msz_cmd(args);
            break;
        case "bct" :
            bct_cmd(args);
            break;
        case "tna" :
            tna_cmd(args);
            break;
        case "pnw" :
            pnw_cmd(args);
            break;
        case "ppo" :
            ppo_cmd(args);
            break;
        case "plv" :
            plv_cmd(args);
            break;
        case "pdi" :
            pdi_cmd(args);
            break;
        case "pin" :
            pin_cmd(args);
            break;
        case "sgt" :
            sgt_cmd(args);
            break;
    }
}
function Disconnect(IP, Port) {
    client.end();
    Connected = false;
}

/*
** Function WEB
*/

app.use(function (req, res, next) {
    // Website you wish to allow to connect
    res.setHeader('Access-Control-Allow-Origin', '*');
    // Request methods you wish to allow
    res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');
    // Request headers you wish to allow
    res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');
    // Set to true if you need the website to include cookies in the requests sent
    // to the API (e.g. in case you use sessions)
    res.setHeader('Access-Control-Allow-Credentials', true);
    // Pass to next layer of middleware
    next();
});
app.get('/Maps', function (req, res) {
    console.log(Maps);
    res.json(Maps);
});
app.get('/Case', function (req, res) {
    if (req.query.posX && req.posY && maps 
            && maps.sizeX > req.query.posX 
            &&  maps.sizeY > req.query.posY) {
        res.json({Case: maps.Case[req.query.posX][req.query.posY]});
    }
    res.json({Case: null});
});
app.get('/TeamName', function (req, res) {
    res.json({TeamName: TeamName});
});
app.get('/Players', function (req, res) {
    res.json({Players: PlayerList});
});
app.get('/Player', function (req, res) {
    if (req.query.id) {
        res.json({Player: PlayerList[id]});
    }
    res.json({Player: null});
});
app.get('/Disconnect', function (req, res) {
    Disconnect();
    res.json({ret: "Disconnected"});
});

var ResponsOtherFunc;

app.get('/Connect', function(req, resp) {
    var ret = "Bad Arguments";
    if (Connected === false) {
        console.log("IP : " + req.query.ip);
        console.log("Port : " + req.query.port);
        if (req.query.ip != null && req.query.port != null) {
            try {
                ResponsOtherFunc = resp;
                client.connect(req.query.port, req.query.ip, function() {
                    ConnectionArgs = {ip: req.query.ip, port: req.query.port}
                    Connected = true;
                    ret = "Connected";
                    resp.json({ret: ret});
                });
            } catch (ex) {
                console.log("Exception : " + ex);
                ret = "Connection Failed :" + ex;
                resp.json({ret: ret});
                ConnectionArgs = null;
            }
        }
        else {
            resp.json({ret: ret});
        }
    } else {
        ret = "Already connected";
        resp.json({ret: ret});
    }
});
app.get('/ConnectionArgs', function (req, resp) {
    resp.json(ConnectionArgs);
});
app.get('/AskRefresh', function (req, resp) {
    if (Connected) {
        PlayerList.forEach(function (item, index) {
            client.write("ppo "  + item.id + "\n");
            client.write("plv "  + item.id + "\n");
            client.write("pin "  + item.id + "\n");
            client.write("sgt\n");
        });
        resp.json({ret: "Command Send"});
    } else 
        resp.json({ret: "Disconnected"});
});
app.get('/SetTimeRefresh', function (req, resp) {
    if (Connected) {
        client.write("sst " + req.query.time + "\n");
        resp.json({ret: "Command Send"});
    }else {
        resp.json({ret: "Disconnected"});
    }
});
app.get('/GetTimeRefresh', function (req, resp) {
    if (Connected) {
        resp.json({time: sgtValue});
    }else {
        resp.json({ret: "Disconnected"});
    }
});
app.listen(port);
/*
** Action Socket
*/

client.on('data', function(data) {
    var textdata = data.toString('utf8');
    if (data[data.length - 1] == 10) {
        buffer += textdata;
        var line = buffer.split("\n");
        line.forEach(ExecLine);
        buffer = "";
    } else {
        buffer += textdata;
    }
});
client.on('close', function() {
    buffer = "";
    ResetClient();
	console.log('Connection closed');
});
client.on('error', function(err) {
	ret = err;
	ResponsOtherFunc.json({ret: ret});
    ResponsOtherFunc = null;
})
