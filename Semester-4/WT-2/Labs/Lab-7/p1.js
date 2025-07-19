// Create a hello world webapp using ExpressJS. (A)

const express = require('express')

app = express()

app.get('/',(req,res)=>{
    res.send("Hello World")
})

app.listen(8000,()=>{
    console.log("Server Started at @ 8000")
})