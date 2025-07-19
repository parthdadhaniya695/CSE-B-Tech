import Link from "next/link";

async function Students() {
  const res = await fetch("https://6875d513814c0dfa6539907e.mockapi.io/students", {
    next: { revalidate: 0 },
  });
  const data = await res.json();

  return (
    <div className="p-6">
      <h2 className="text-3xl font-bold mb-4 text-gray-800">Student Directory</h2>
      <ul className="space-y-3">
        {data.map((d: any) => (
          <li key={d.id}>
            <h1>
              <Link
                href={`/students/${d.id}`}
                className="text-blue-600 hover:text-blue-800 underline hover:no-underline text-xl transition-colors"
              >
                {d.name}
              </Link>
            </h1>
          </li>
        ))}
      </ul>
    </div>
  );
}

export default Students;
