import { useState } from "react";

function Calculator(){

    const [input, setInput] = useState("");

    const handleClick = (value) => {
        if (value === "C") {
            setInput("");
        } else if (value === "=") {
            try {
                setInput(eval(input).toString());
            } catch {
                setInput("Error");
            }
        } else {
            setInput(input + value);
        }
    };

    return(
    <div class="div" style={{alignContent: "center"}}>
    <table align="center">
        <tr>
            <td colspan="4"><input type="text" id="input" value={input} disabled/></td>
        </tr>
        <tr>
            <td><input type="button" value="7" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="8" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="9" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="C" onClick={(e)=>{handleClick(e.target.value)}}/></td>
        </tr>
        <tr>
            <td><input type="button" value="4" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="5" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="6" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="+" onClick={(e)=>{handleClick(e.target.value)}}/></td>
        </tr>
        <tr>
            <td><input type="button" value="1" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="2" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="3" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="-" onClick={(e)=>{handleClick(e.target.value)}}/></td>
        </tr>
        <tr>
            <td><input type="button" value="0" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="*" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="/" onClick={(e)=>{handleClick(e.target.value)}}/></td>
            <td><input type="button" value="=" onClick={(e)=>{handleClick(e.target.value)}}/></td>
        </tr>
    </table>
    </div>
    );
}

export default Calculator;

