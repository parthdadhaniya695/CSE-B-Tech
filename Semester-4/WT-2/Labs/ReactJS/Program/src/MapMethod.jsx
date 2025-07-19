import React from "react";

const data = [
    {
        name: "Parth",
        age: 21
    },
    {
        name: "Rushi",
        age: 19
    },
    {
        name: "Devesh",
        age: 18
    },
    {
        name: "Harsh",
        age: 18
    },

]


function Mapdemo() {
    return (
        <>
            {
                data.map((data) => {
                    return (
                        <>
                            <div class="card" >
                                    <div class="card-body">
                                        <h5 class="card-title">{data.name}</h5>
                                        <p class="card-text">{data.age}</p>
                                    </div>
                            </div>
                        </>
                    )
                })
            }
        </>
    )
}


export default Mapdemo;