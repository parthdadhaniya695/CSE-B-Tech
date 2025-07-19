// Create a webapp with 5 pages like about, contact etc.. using ExpressJS. (B)

const express = require('express');

app = express();

app.get('/',(req,res)=>{
    res.send("Home Page");
});

app.get('/about',(req,res)=>{
    res.send("About Page");
});

app.get('/contact',(req,res)=>{
    res.send("Contact Page");
});

app.get('/blog',(req,res)=>{
    res.send("Blog Page");
});

app.get('/service',(req,res)=>{
    res.send("Service Page");
});

app.listen(8000,()=>{
    console.log("Server Started at @ 8000");
})