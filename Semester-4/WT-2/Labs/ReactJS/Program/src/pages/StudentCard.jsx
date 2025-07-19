import React from "react";
import { Link } from "react-router-dom";
import Header from "../parts/Header";

const Students = [
  {
    createdAt: "2024-11-27T07:57:07.059Z",
    StudentName: "JK",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107078---14-10-2023-11-30-59.JPG",
    StudentInitial: "VI",
    StudentDateOfBirth: "1994-04-29T11:57:31.045Z",
    id: "1",
  },
  {
    createdAt: "2024-11-28T00:32:19.414Z",
    StudentName: "Karmdeep",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107022---19-05-2023-08-57-35.JPG",
    StudentInitial: "MD",
    StudentDateOfBirth: "1235-09-23T07:46:25.773Z",
    id: "2",
  },
  {
    createdAt: "2024-11-28T01:06:15.172Z",
    StudentName: "Yashraj",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107080---19-05-2023-12-18-55.JPG",
    StudentInitial: "PS",
    StudentDateOfBirth: "1998-11-27T21:21:13.209Z",
    id: "3",
  },
  {
    createdAt: "2024-11-28T06:20:28.398Z",
    StudentName: "LalBhai Ahir",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107074---17-10-2023-10-06-28.JPG",
    StudentInitial: "GT",
    StudentDateOfBirth: "1993-12-10T00:13:11.739Z",
    id: "4",
  },
  {
    createdAt: "2024-11-27T23:11:40.406Z",
    StudentName: "Abhi Raj",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107033---01-04-2024-01-16-20.jpg",
    StudentInitial: "YT",
    StudentDateOfBirth: "1998-03-28T03:53:49.468Z",
    id: "5",
  },
  {
    createdAt: "2024-11-27T12:37:01.187Z",
    StudentName: "Jay",
    StudentImage:
      "https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107022---19-05-2023-08-57-35.JPG",
    StudentInitial: "NL",
    StudentDateOfBirth: "1948-08-12T19:42:41.267Z",
    id: "6",
  },
];

function StudentCard() {
  return (
    <div className="container mx-auto p-4 grid grid-cols-1 md:grid-cols-3 gap-6">
      {Students.map((student) => (
        <div
          key={student.id}
          className="bg-white rounded-lg shadow-md p-4 flex flex-col items-center border border-gray-200"
        >
          <img
            src={student.StudentImage}
            alt={student.StudentName}
            className="w-24 h-24 rounded-full object-cover border-2 border-gray-300"
          />
          <h2 className="mt-3 text-lg font-semibold">{student.StudentName}</h2>
          <p className="text-sm text-gray-600">Initial: {student.StudentInitial}</p>
          <p className="text-sm text-gray-600">DOB: {new Date(student.StudentDateOfBirth).toDateString()}</p>
          <p className="text-xs text-gray-500 mt-2">Created At: {new Date(student.createdAt).toDateString()}</p>
        </div>
      ))}
    </div>
  );
}

export default StudentCard;