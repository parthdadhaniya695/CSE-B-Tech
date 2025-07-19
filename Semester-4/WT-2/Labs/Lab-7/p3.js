// Create a webapp in NodeJS which reads 􀆒les like about.txt, contact.txt and display it using http core module. (C)

const express = require('express');

const fs = require('fs');

const app = express();

app.get('/',(req,res)=>{
    const data = fs.readFileSync('home.txt','utf-8');
    res.write(data);
    res.end();

});

app.get('/about',(req,res)=>{
    const data = fs.readFileSync('about.txt','utf-8');
    res.write(data);
    res.end();

});

app.get('/contact',(req,res)=>{
    const data = fs.readFileSync('contact.txt','utf-8');
    res.write(data);
    res.end();

});

app.listen(3000,()=>{
    console.log("Server Started at @ 8000");
})