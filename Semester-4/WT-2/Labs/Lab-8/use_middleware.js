// Demonstrate the use of middleware in Express. (A)

const express = require('express');

const app = express();

app.use('/student',(req,res,next)=>{
    console.log('middleware called');
    next();
});

app.get('/student',(req,res)=>{
    res.send('Hello World-1');
});

app.get('/student/api',(req,res)=>{
    res.send('Hello World-2');
});

app.get('/api/student',(req,res)=>{
    res.send('Hello World-3');
});

app.listen(8000,()=>{
    console.log('Server Started @ 8000');
});