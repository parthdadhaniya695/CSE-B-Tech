const mongoose = require('mongoose');
const Student = require('./model/Student');
const express = require('express');
const bodyParser = require('body-parser');

const atlasUrl = "mongodb+srv://24010101621:parth123@cluster0.66snu.mongodb.net/";

mongoose.connect(atlasUrl).then(()=>{
    console.log("DB Connected");

    const app = express();

    app.use(bodyParser.json());

    //getAll
    app.get("/student",async (req,res)=>{
        const data = await Student.find();
        res.send(data);
    });

    //getByID
    app.get("/student/:id",async (req,res)=>{
        const data = await Student.findOne({StudentID:req.params.id});
        res.send(data);
    });

    //insert (Create)
    app.post("/student", async (req,res)=>{
        const obj = new Student({
            StudentID:req.body.StudentID,
            StudentName:req.body.StudentName,
            StudentMobile: req.body.StudentMobile,
            StudentBranch: req.body.StudentMobile
        });
        const data = await obj.save();
        res.send(data);

    });

    //update
    app.patch("/student/:id", async (req,res)=>{
        let stu = await Student.findOne({_id:req.params.id});
            stu.StudentID = req.body.StudentID,
            stu.StudentName = req.body.StudentName,
            stu.StudentMobile = req.body.StudentMobile,
            stu.StudentBranch = req.body.StudentMobile
        const data = await stu.save();
        res.send(data);
    });

    //delete
    app.delete("/student/:id", async (req,res)=>{
        const data = await Student.deleteOne({_id:req.params.id});
        res.send(data)
    });

    app.listen(3000,()=>{
        console.log("Server Started @ 3000");
    })
});