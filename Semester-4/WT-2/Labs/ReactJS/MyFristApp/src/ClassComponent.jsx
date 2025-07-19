import { Component } from "react";
import HellloWorld from "./HelloWorld";
import GoodMorning from "./GoodMorning";

class ClassComponent extends Component{
    render(){
        return(
            <>
                <HellloWorld/>
                <GoodMorning/>
            </>
        )
    }
}

export default ClassComponent