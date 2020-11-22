const http = require("http");

// List of names for reference
names = [
  "TEST PERSON",
  "Alex",
  "Alissa",
  "Amrita",
  "Chinmai",
  "Deborah",
  "Devon",
  "Gil",
  "Hoeffel",
  "Isabelle",
  "Jenny",
  "Keon",
  "Milla",
  "Naomi",
  "Owen",
  "Patrick",
  "Raina",
  "Seamus",
  "Tess",
  "Vasco",
];
class color {
  constructor(red = 0, green = 0, blue = 0) {
    this.red = red;
    this.green = green;
    this.blue = blue;
    this.rgb = [red, green, blue];
  }
}
class Person {
  constructor(name) {
    this.online = false;
    this.name = "";
    this.lit = true;
    this.red = 0;
    this.green = 0;
    this.blue = 0;
    this.time = 0;
    this.currentUpdate = 0;
  }
  update(HTTPRequestBody) {
    this.lit = true;
    this.color = new color();
  }
}

// Defines people
people = Array(20).fill(new Person());
for (let i = 0; i < people.length; i++) {
  people[i].name = names[i];
}

// Create an initial update to send out
lastestUpdate = 1;



const WebSocket = require('ws');
 
const wss = new WebSocket.Server({ port: 8080 });
 
wss.on('connection', function connection(ws) {
  ws.on('message', function incoming(message) {
    console.log('received: %s', message);
  });
 
  ws.send('something');
});

// http
//   .createServer((request, response) => {
//     const { headers, method, url } = request;
//     let body = [];
//     request
//       .on("error", (err) => {
//         //console.error(err);
//       })
//       .on("data", (chunk) => {
//         body.push(chunk);
//       })
//       .on("end", () => {
//         body = Buffer.concat(body).toString();
//         response.on("error", (err) => {
//           //console.error(err);
//         });

//         console.log("Receive request of type: " + method + " to " + url);
//         if (method == "GET") {
//           const responseBody = httpGetHandler(people);
//           //console.log(responseBody);
//           response.end(JSON.stringify(responseBody));
//         }

//         // POST request, hopefully a lightmark is updating data?
//         if (method == "POST") {
//           if (validatePost(url, body)) {
//             people[getPersonByUrl(url)].update(getColorByBody(body));
//             updater.emit("update");
//             lastestUpdate++;
//           } else {
//             response.statusCode = 400;
//             response.end();
//           }
//         }
//       });
//   })
//   .listen(8080);

// // Define these shits properly when you get the time
// function getPersonByUrl(url) {
//   return 0;
// }
// function getColorByBody(body) {
//   return new color(255, 255, 255);
// }

// function httpGetHandler(url) {
//   switch (url) {
//     case "/favicon.ico":
//       console.log("Request For icon");
//       return {};
//       break;
//     case "/statusPage":
//       console.log("returning debug/status webpage");
//       console.log("");
//       return people;
//     case "/statusUpdate":
//       console.log("returning status update");
//       return getUpdate();
//     default:
//       console.log("returning base of people");
//       return { people, lastestUpdate };
//   }
// }

// // Jank af, every post is valid
// function validatePost(url, body) {
//   return true;
// }

// const EventEmitter = require("events");
// const updater = new EventEmitter();

// async function getUpdate() {
//   updadter.on("update", () => {
//     return { lastestUpdate, people };
//   });
//   updater.on("timeout", () => {
//     return { lastestUpdate, people };
//   });
// }

// // request times out after a minute, latest update does not change
// async function requestTimeOut() {
//   return setTimeout(() => {
//     updater.emit("timeout");
//   }, 60000);
// }
