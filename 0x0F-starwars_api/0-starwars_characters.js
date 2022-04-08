#!/usr/bin/node
const request = require('request');
const filmId = process.argv[2];
const filmUrl = `https://swapi-api.hbtn.io/api/films/${filmId}/`;

function firstInter () {
  return new Promise((resolve, reject) => {
    request.get({ url: filmUrl, json: true }, function (error, response, body) {
      if (!error && response.statusCode === 200) {
        resolve(body);
      }
    });
  });
}

function secondInter (urlTofetch) {
  return new Promise((resolve, reject) => {
    request.get(
      { url: urlTofetch, json: true },
      function (error, response, body) {
        if (!error && response.statusCode === 200) {
          resolve(body);
        }
      }
    );
  });
}

async function main () {
  const data = await firstInter();
  for (const datechar of data.characters) {
    const datachar = await secondInter(datechar);
    console.log(datachar.name);
  }
}

main();
