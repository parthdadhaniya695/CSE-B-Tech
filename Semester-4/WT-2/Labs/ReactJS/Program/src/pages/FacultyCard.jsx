import React from "react";
import { Link } from "react-router-dom";



    const faculties = [
      {
        createdAt: "2024-11-27T07:57:07.059Z",
        FacultyName: "Pradyuman Sir",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/6---28-04-2023-02-06-07.jpg",
        FacultyInitial: "VI",
        FacultyDescription: "DS Faculty",
        FacultyDateOfBirth: "1994-04-29T11:57:31.045Z",
        id: "1"
      },
      {
        createdAt: "2024-11-28T00:32:19.414Z",
        FacultyName: "Shruti Mam",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/336---28-04-2023-01-34-37.jpg",
        FacultyInitial: "MD",
        FacultyDescription: "Python Faculty",
        FacultyDateOfBirth: "1235-09-23T07:46:25.773Z",
        id: "2"
      },
      {
        createdAt: "2024-11-28T01:06:15.172Z",
        FacultyName: "Nilesh Sir",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/3---28-04-2023-02-02-42.jpg",
        FacultyInitial: "PS",
        FacultyDescription: "Staff",
        FacultyDateOfBirth: "1998-11-27T21:21:13.209Z",
        id: "3"
      },
      {
        createdAt: "2024-11-28T06:20:28.398Z",
        FacultyName: "Firoz Sir",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/12---28-04-2023-02-06-51.jpg",
        FacultyInitial: "GT",
        FacultyDescription: "Dbms Faculty",
        FacultyDateOfBirth: "1993-12-10T00:13:11.739Z",
        id: "4"
      },
      {
        createdAt: "2024-11-27T23:11:40.406Z",
        FacultyName: "Rupesh Sir",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/10---28-04-2023-02-07-03.jpg",
        FacultyInitial: "YT",
        FacultyDescription: "Staff",
        FacultyDateOfBirth: "1998-03-28T03:53:49.468Z",
        id: "5"
      },
      {
        createdAt: "2024-11-27T12:37:01.187Z",
        FacultyName: "Swati Mam",
        FacultyImage: "https://du-website.s3.ap-south-1.amazonaws.com/U01/Faculty-Photo/11---29-04-2023-01-44-21.jpg",
        FacultyInitial: "NL",
        FacultyDescription: "Java Faculty",
        FacultyDateOfBirth: "1948-08-12T19:42:41.267Z",
        id: "6"
      }
    ]


    function FacultyCard() {
      return (
          <div className="container grid grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4 gap-4 p-4">
              {faculties.map((faculty) => (
                  <div key={faculty.FacultyName} className="border rounded-lg shadow-lg p-4">
                      <img 
                          src={faculty.FacultyImage} 
                          alt={faculty.FacultyName} 
                          className="w-full h-40 object-cover rounded-md"
                      />
                      <h2 className="text-lg font-bold mt-2">{faculty.FacultyName}</h2>
                      <p className="text-gray-700">Initial: {faculty.FacultyInitial}</p>
                      <p className="text-gray-600">{faculty.FacultyDescription}</p>
                      <p className="text-gray-500 text-sm">Date of Birth: {faculty.FacultyDateOfBirth}</p>
                  </div>
              ))}
          </div>
      );
  }
    

export default FacultyCard