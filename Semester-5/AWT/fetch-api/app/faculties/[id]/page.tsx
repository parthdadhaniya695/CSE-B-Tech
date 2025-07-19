import Link from 'next/link';
import React from 'react'

async function FacultyDetail({params}:{params: Promise<{id:number}>}) {
  const { id } = await params;
  const res = await fetch("https://6875d513814c0dfa6539907e.mockapi.io/faculties/" + id);
  const data = await res.json();

  return (
    <div className="max-w-md mx-auto mt-10 p-6 bg-white rounded-xl shadow-lg">
      <h1 className="text-3xl font-bold text-gray-800 mb-4">{data.FacultyName}</h1>
      <h3 className="text-3xl font-bold text-gray-800 mb-4">{data.FacultyEmail}</h3>
      <img
        src={data.FacultyImage}
        alt={data.FacultyName}
        className="w-full h-auto rounded-lg border border-gray-200 mb-6"
      />
      <Link href="/students">
        <button className="text-white bg-blue-600 hover:bg-blue-700 px-4 py-2 rounded-md transition duration-200">
          ← Back
        </button>
      </Link>
    </div>
  );
}

export default FacultyDetail