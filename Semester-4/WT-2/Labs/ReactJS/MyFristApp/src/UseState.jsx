import React, { useEffect, useState } from "react";

const Counter = () => {
    const [count, setCount] = useState(0);
    useEffect(()=>{
            console.log("Hello World");
        },[count])

    return (
        <div className="flex flex-col items-center p-4 space-y-2">
            <h1 className="text-2xl font-bold">Counter: {count}</h1>

            <button
                className="px-4 py-2 bg-blue-500 me-2 text-white rounded-md"
                onClick={() => setCount(count + 1)}
            >
                Increment++
            </button>

            <button
                className="px-4 py-2 bg-blue-500 me-2 text-white rounded-md"
                onClick={() => setCount(count-1 > 0 ? count-1 : 0)}
            >
                Decrement--
            </button>

            <button
                className="px-4 py-2 bg-blue-500 me-2 text-white rounded-md"
                onClick={() => setCount(0)}
            >
                Reset
            </button>

            <button
                className="px-4 py-2 bg-blue-500 me-2 text-white rounded-md"
                onClick={() => setCount(count + 5)}
            >
                INC BY 5++
            </button>

            <button
                className="px-4 py-2 bg-blue-500 text-white rounded-md"
                onClick={() => setCount(count-5 > 0 ? count-5 : 0)}
            >
                DEC BY 5--
            </button>
        </div>
    );
};

export default Counter;
