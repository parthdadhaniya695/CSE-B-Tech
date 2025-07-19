import { useState } from "react";

export default function InputLogger() {
  const [inputValue, setInputValue] = useState("");
  const [submittedValue, setSubmittedValue] = useState("");

  const handleChange = (e) => {
    setInputValue(e.target.value);
    console.log("Input changed:", e.target.value);
  };

  const handleSubmit = () => {
    setSubmittedValue(inputValue);
    console.log("Submitted value:", inputValue);
  };

  return (
    <div className="container mt-4 text-center">
      <input 
        type="text" 
        value={inputValue} 
        onChange={handleChange} 
        placeholder="Enter Data" 
        className="form-control mb-3"
      />
      <button onClick={handleSubmit} className="btn btn-primary mb-3">
        Submit
      </button>
      {submittedValue && (
        <div className="mt-2">
          <strong>Submitted Output:</strong> {submittedValue}
        </div>
      )}
    </div>
  );
}