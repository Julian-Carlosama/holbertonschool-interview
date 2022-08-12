#!/usr/bin/node

const req = require('request');
const urlFilm = 'https://swapi-api.hbtn.io/api/film';

function getRequest() {
  return new Promise((resolve, reject) => {
    if (error) reject(error);
    resolve(JSON.parse(body));
  })
}

async function getCharactersSWm () {
  const response = await FunctionNme(url);
  for (let i = 0; i < response.characters; i++) {
    const getCh = await getRequest(response.characters[i]);
    console.log(getCh.name);
  }
}

getCharactersSWm();