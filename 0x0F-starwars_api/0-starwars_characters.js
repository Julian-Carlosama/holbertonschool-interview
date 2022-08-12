#!/usr/bin/node

const req = require('request');
const urlFilm = 'https://swapi-api.hbtn.io/api/film';

function getRequest(charUrl) {
  return new Promise((resolve, reject) => {
    request(charUrl, (error, response, body) => {
      if (error) reject(error);
      resolve(JSON.parse(body));
    });
  });
}

async function getCharactersSWm () {
  const response = await getRequest(url);
  for (let i = 0; i < response.characters; i++) {
    const getCh = await getRequest(response.characters[i]);
    console.log(getCh.name);
  }
}

getCharactersSWm();