import { Outlet } from "react-router-dom";
import Header from "./Header";

function Layout(){
    return(
        <>
            <div className="container">
                <div className="row">
                    <div className="col">
                        <Header/>
                    </div>
                </div>
                <div className="row">
                    <div className="col p-3">
                        <Outlet/>
                    </div>
                </div>
            </div>
            
        </>
    );
}

export default Layout;