#!/usr/bin/node

const req = require('request');
const urlFilm = 'https://swapi-api.hbtn.io/api/';

async function getCharactersSWm () {
  const response = await FunctionNme(url);
  for (let i = 0; i < response.characters; i++) {
    const getCh = await getRequest(response.characters[i]);
    console.log(getCh.name);
  }
}

getCharactersSWm();