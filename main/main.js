import { Express } from "express";
import { Socket } from "socket.io";
import { SerialPort } from "serialport";
const http = require('http')




const ReadLine = SerialPort.parses.ReadLine;
const parser = new ReadLine({delimiter: "\r\n"});
const inputSerial = new SerialPort("PUT YOUR COMS INPUT ", {

    baudRate: 9600,


});

inputSerial.pipe(parser);

inputSerial.on("open", function (){

    console.log("Conexao Estabelecida!!")



})



