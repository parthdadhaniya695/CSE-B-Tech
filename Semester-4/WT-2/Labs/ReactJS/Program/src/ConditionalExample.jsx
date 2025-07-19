import React from "react";

function Conditional_rendering({isDisplay}){

    return (
        <>
            {!isDisplay ? (<h1>Isdisplay is true and display is rendering</h1>) : (<h1>Isdisplay is false and displayis not rendering</h1>)}
        </>  
    )    
}

export default Conditional_rendering;