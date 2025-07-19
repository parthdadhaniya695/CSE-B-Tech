const mongoose = require('mongoose');

const schema = mongoose.Schema({
    StudentID: Number,
    StudentName: String,
    StudentMobile: Number,
    StudentBranch: String
})

module.exports = mongoose.model("Student",schema);