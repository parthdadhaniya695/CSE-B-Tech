import React, { useEffect, useState } from "react";

const UseEffectDemo = () => {
    const [data, setData] = useState("");

    useEffect(()=>{
        setTimeout(()=>{
            setData("Data Feched");
        },3000)
    },[])

    return (
        <div className="flex flex-col items-center p-4">
            <h1>Data is coming after 3 second</h1>
            <h1 className="text-2xl font-bold">{data}</h1>
        </div>
    );
};

export default UseEffectDemo;
