import { useState } from "react";

const ProductCRUD = () => {
  const [products, setProducts] = useState([
    { id: 1, name: "Pendrive", price: 900 },
    { id: 2, name: "Keyboard", price: 1900 },
    { id: 3, name: "Mouse", price: 1000 },
  ]);

  const [newProduct, setNewProduct] = useState({ name: "", price: "" });
  const [editId, setEditId] = useState(null);

  const handleAddEdit = () => {
    if (editId !== null) {
      setProducts(
        products.map((product) =>
          product.id === editId ? { ...product, ...newProduct } : product
        )
      );
      setEditId(null);
    } else {
      setProducts([...products, { id: Date.now(), ...newProduct }]);
    }
    setNewProduct({ name: "", price: "" });
  };

  const deleteProduct = (id) => {
    setProducts(products.filter((product) => product.id !== id));
  };

  return (
    <div className="max-w-lg mx-auto mt-10 p-5 bg-white shadow-md rounded-lg">
      <h2 className="text-xl font-bold mb-4">Product Management</h2>

      {/* Input Fields */}
      <div className="flex gap-2 mb-4">
        <input
          type="text"
          placeholder="Product Name"
          value={newProduct.name}
          onChange={(e) => setNewProduct({ ...newProduct, name: e.target.value })}
          className="border p-2 rounded w-full"
          required
        />
        <input
          type="number"
          placeholder="Price"
          value={newProduct.price}
          onChange={(e) => setNewProduct({ ...newProduct, price: e.target.value })}
          className="border p-2 rounded w-32"
          required
        />
        <button
          onClick={handleAddEdit}
          className="bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600"
        >
          Submit
        </button>
      </div>

      {/* Product Table*/}
      <table className="table mt-5 w-full border-collapse border border-gray-200">
        <thead>
          <tr className="bg-gray-100">
            <th className="border p-2">Id</th>
            <th className="border p-2">Name</th>
            <th className="border p-2">Price</th>
            <th className="border p-2">Actions</th>
          </tr>
        </thead>
        <tbody>
          {products.map((prod) => (
            <tr key={prod.id} className="text-center">
              <td className="border p-2">{prod.id}</td>
              <td className="border p-2">{prod.name}</td>
              <td className="border p-2">{prod.price}</td>
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

export default ProductCRUD;
