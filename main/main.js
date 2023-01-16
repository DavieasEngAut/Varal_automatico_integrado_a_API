const Express  = require('serialport')
const Socket = require('socket.io')
const http = require('http')


const app = Express();

app.get('/', (req, res) => {
    res.send('Integration Arduino with NodeJS');
  });
  
  // Start the server on port 3000
  app.listen(8080, () => {
    console.log('Server Started in port 8080');
  });






const ReadLine = SerialPort.parses.ReadLine;
const parser = new ReadLine({delimiter: "\r\n"});
const inputSerial = new SerialPort("PUT YOUR COMS INPUT ", {

    baudRate: 9600,


});

inputSerial.pipe(parser);

inputSerial.on("open", function (){

    console.log("Conexao Estabelecida!!")



})



