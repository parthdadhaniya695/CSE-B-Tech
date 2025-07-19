import React from "react";

function EventHandlingExample(){

    const handleClick=()=>{
    console.log("hello world");
};

return(
    <div>
        <button onClick={handleClick}>Click</button>
    </div>
);
}

export default EventHandlingExample;
