#!/usr/bin/node

const request = require('request');
const urlFilm = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

function getRequest (charUrl) {
  return new Promise((resolve, reject) => {
    request(charUrl, (error, response, body) => {
      if (error) reject(error);
      resolve(JSON.parse(body));
    });
  });
}

async function getCharactersSWm () {
  const response = await getRequest(urlFilm);
  for (let i = 0; i < response.characters.length; i++) {
    const getCh = await getRequest(response.characters[i]);
    console.log(getCh.name);
  }
}

getCharactersSWm();
