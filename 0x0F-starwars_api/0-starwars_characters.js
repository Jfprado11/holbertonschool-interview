#!/usr/bin/node
const request = require('request');
const filmId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

function firstInter() {
  return new Promise((resolve, reject) => {
    request.get({ url: filmUrl, json: true }, function (error, response, body) {
      if (!error && response.statusCode === 200) {
        resolve(body);
      }
    });
  });
}

function secondInter(urlTofetch) {
  return new Promise((resolve, reject) => {
    request.get(
      { url: urlTofetch, json: true },
      function (error, response, body) {
        if (!error && response.statusCode === 200) {
          console.log(body.name);
          resolve(body);
        }
      }
    );
  });
}

async function main() {
  const data = await firstInter();
  data.characters.forEach(async (element) => {
    const dataChar = await secondInter(element);
    // console.log(dataChar.name);
  });
}

main();
