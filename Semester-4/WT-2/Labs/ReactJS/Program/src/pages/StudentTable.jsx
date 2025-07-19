import React from "react";
import { Link } from "react-router-dom";
import Header from "../parts/Header";


  const Students = [
      {
        createdAt: "2024-11-27T07:57:07.059Z",
        StudentName: "JK",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107078---14-10-2023-11-30-59.JPG",
        StudentInitial: "VI",
        StudentDateOfBirth: "1994-04-29T11:57:31.045Z",
        id: "1"
      },
      {
        createdAt: "2024-11-28T00:32:19.414Z",
        StudentName: "Karmdeep",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107022---19-05-2023-08-57-35.JPG",
        StudentInitial: "MD",
        StudentDateOfBirth: "1235-09-23T07:46:25.773Z",
        id: "2"
      },
      {
        createdAt: "2024-11-28T01:06:15.172Z",
        StudentName: "Yashraj",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107080---19-05-2023-12-18-55.JPG",
        StudentInitial: "PS",
        StudentDateOfBirth: "1998-11-27T21:21:13.209Z",
        id: "3"
      },
      {
        createdAt: "2024-11-28T06:20:28.398Z",
        StudentName: "LalBhai Ahir",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107074---17-10-2023-10-06-28.JPG",
        StudentInitial: "GT",
        StudentDateOfBirth: "1993-12-10T00:13:11.739Z",
        id: "4"
      },
      {
        createdAt: "2024-11-27T23:11:40.406Z",
        StudentName: "Abhi Raj",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107033---01-04-2024-01-16-20.jpg",
        StudentInitial: "YT",
        StudentDateOfBirth: "1998-03-28T03:53:49.468Z",
        id: "5"
      },
      {
        createdAt: "2024-11-27T12:37:01.187Z",
        StudentName: "Jay",
        StudentImage:"https://du-website.s3.ap-south-1.amazonaws.com/U01/Student-Photo/200540107022---19-05-2023-08-57-35.JPG",
        StudentInitial: "NL",
        StudentDateOfBirth: "1948-08-12T19:42:41.267Z",
        id: "6"
      }
  ];

  function StudentTable() {
    return (
        <div className="container">
            <table className="table">
                <thead>
                    <tr>
                        <th>Student Name</th>
                        <th>Image</th>
                        <th>Initial</th>
                        <th>Date of Birth</th>
                        <th>Created At</th>
                    </tr>
                </thead>
                <tbody>
                    {
                        Students.map((Student) => {
                            return (
                                <tr key={Student.StudentName}>
                                    <td>{Student.StudentName}</td>
                                    <td><img src={Student.StudentImage} alt={Student.StudentName} style={{ width: '50px' }} /></td>
                                    <td>{Student.StudentInitial}</td>
                                    <td>{Student.StudentDateOfBirth}</td>
                                    <td>{Student.createdAt}</td>
                                </tr>
                            );
                        })
                    }
                </tbody>
            </table>
        </div>
    );
}


export default StudentTable