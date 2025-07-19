import { useState } from "react";

const FacultyCRUD = () => {
  const [faculty, setFaculty] = useState([
    { id: 1, name: "Dr. Smith", department: "Physics", email: "smith@uni.edu", phone: "1234567890" },
    { id: 2, name: "Dr. Johnson", department: "Mathematics", email: "johnson@uni.edu", phone: "0987654321" },
  ]);

  const [newFaculty, setNewFaculty] = useState({ name: "", department: "", email: "", phone: "" });
  const [editId, setEditId] = useState(null);

  const handleAddEdit = () => {
    if (editId !== null) {
      setFaculty(
        faculty.map((f) => (f.id === editId ? { ...f, ...newFaculty } : f))
      );
      setEditId(null);
    } else {
      setFaculty([...faculty, { id: Date.now(), ...newFaculty }]);
    }
    setNewFaculty({ name: "", department: "", email: "", phone: "" });
  };

  const deleteFaculty = (id) => {
    setFaculty(faculty.filter((f) => f.id !== id));
  };

  return (
    <div className="max-w-lg mx-auto mt-10 p-5 bg-white shadow-md rounded-lg">
      <h2 className="text-xl font-bold mb-4">Faculty Management</h2>

      {/* Input Fields */}
      <div className="flex flex-col gap-2 mb-4">
        <input
          type="text"
          placeholder="Name"
          value={newFaculty.name}
          onChange={(e) => setNewFaculty({ ...newFaculty, name: e.target.value })}
          className="border p-2 rounded w-full"
          required
        />
        <input
          type="text"
          placeholder="Department"
          value={newFaculty.department}
          onChange={(e) => setNewFaculty({ ...newFaculty, department: e.target.value })}
          className="border p-2 rounded w-full"
          required
        />
        <input
          type="email"
          placeholder="Email"
          value={newFaculty.email}
          onChange={(e) => setNewFaculty({ ...newFaculty, email: e.target.value })}
          className="border p-2 rounded w-full"
          required
        />
        <input
          type="tel"
          placeholder="Phone"
          value={newFaculty.phone}
          onChange={(e) => setNewFaculty({ ...newFaculty, phone: e.target.value })}
          className="border p-2 rounded w-full"
          required
        />
        <button
          onClick={handleAddEdit}
          className="bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600"
        >
          {editId !== null ? "Update" : "Add"} Faculty
        </button>
      </div>

      {/* Faculty Table*/}
      <table className="table-auto w-full mt-5 border-collapse border border-gray-200">
        <thead>
          <tr className="bg-gray-100">
            <th className="border p-2">Id</th>
            <th className="border p-2">Name</th>
            <th className="border p-2">Department</th>
            <th className="border p-2">Email</th>
            <th className="border p-2">Phone</th>
            <th className="border p-2">Actions</th>
          </tr>
        </thead>
        <tbody>
          {faculty.map((f) => (
            <tr key={f.id} className="text-center">
              <td className="border p-2">{f.id}</td>
              <td className="border p-2">{f.name}</td>
              <td className="border p-2">{f.department}</td>
              <td className="border p-2">{f.email}</td>
              <td className="border p-2">{f.phone}</td>
              <td className="border p-2 flex justify-center gap-2">
              <button
                  className="bg-warning text-white px-3 py-1 rounded-md me-2"
                  onClick={() => {
                    setNewProduct({ name: prod.name, price: prod.price });
                    setEditId(prod.id);
                  }}
                >
                  Edit
                </button>
                <button
                  className="bg-danger text-white px-3 py-1 rounded-md"
                  onClick={() => deleteProduct(prod.id)}
                >
                  Delete
                </button>
              </td>
            </tr>
          ))}
        </tbody>
      </table>
    </div>
  );
};

export default FacultyCRUD;
