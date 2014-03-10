var SerialPort = require("serialport")
var serialport = new SerialPort.SerialPort("/dev/tty.usbmodem1451", {
  baudrate: 9600,
  parser: SerialPort.parsers.readline("\n")
});

var static = require('node-static');
var file = new static.Server('./');

require('http').createServer().listen(8080);

serialport.on("open", function() {

  var app = require('http').createServer(handler)
    , io = require('socket.io').listen(app)
    , fs = require('fs')

  app.listen(3000);

  function handler(request, response) {
    request.addListener('end', function () {
      file.serve(request, response);
    }).resume();
  }

  io.sockets.on('connection', function(socket) {
    serialport.on('data', function(data) {
      socket.emit('data', data);
    });
  });

});
