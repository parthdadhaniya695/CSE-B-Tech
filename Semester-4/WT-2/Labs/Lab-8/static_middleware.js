// Demonstrate the use of static middleware in Express. (A)

const express = require('express');

const app = express();

app.use('/public',express.static("public"));

app.listen(8001,()=>{
    console.log("server is running on port 8001");
});
