import Link from "next/link";

async function Students() {
  const res = await fetch("https://6875d513814c0dfa6539907e.mockapi.io/students", {
    next: { revalidate: 0 },
  });
  const data = await res.json();

  return (
  <div className="p-6 max-w-6xl mx-auto">
    <h2 className="text-4xl font-bold mb-8 text-gray-800 text-center">Student Directory</h2>
    
    <div className="grid gap-6 grid-cols-1 sm:grid-cols-2 md:grid-cols-3 lg:grid-cols-4">
      {data.map((d: any) => (
        <Link
          key={d.id}
          href={`/students/${d.id}`}
          className="block bg-white shadow-md rounded-2xl p-5 hover:shadow-xl transition-shadow border border-gray-100"
        >
          <div className="flex flex-col items-center text-center">
            <div className="w-24 h-24 bg-blue-100 text-blue-600 flex items-center justify-center rounded-full text-2xl font-semibold mb-4">
              {d.StudentName.charAt(0)}
            </div>
            <h3 className="text-lg font-semibold text-gray-800">{d.StudentName}</h3>
          </div>
        </Link>
      ))}
    </div>
  </div>
);
}

export default Students;