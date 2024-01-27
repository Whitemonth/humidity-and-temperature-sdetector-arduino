const http = require("node:http");
const { SerialPort } = require("serialport");
const hostname = "0.0.0.0";
const portH = 80;
const port = new SerialPort({
  path: "COM4",
  baudRate: 115200,
});

let data = {};
let indicators;

port.on("data", function (data) {
  //getting data from COM
  indicators = JSON.parse(data); //parsing JSON
  console.log("Temp: ", indicators.temp);
  console.log("Humidity: ", indicators.humidity);
});

const server = http.createServer((req, res) => {
  //staring a simple http-server for example
  res.statusCode = 200;
  res.setHeader("Content-Type", "text/plain");
  res.end(`Temperature: ${indicators.temp}. Humidity: ${indicators.humidity}`); //show indicators data in UI.
});

server.listen(portH, hostname, () => {
  console.log(`Server running at http://${hostname}:${portH}/`);
});
