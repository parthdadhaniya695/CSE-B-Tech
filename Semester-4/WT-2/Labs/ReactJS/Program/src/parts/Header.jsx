import { Link } from "react-router-dom";

function Header(){
    return(
        <>
            <nav className="navbar navbar-expand-lg bg-body-tertiary">
                <div className="container-fluid">
                    <a className="navbar-brand" href="#">Navbar</a>
                    <button className="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
                    <span className="navbar-toggler-icon"></span>
                    </button>
                    <div className="collapse navbar-collapse" id="navbarSupportedContent">
                    <ul className="navbar-nav me-auto mb-2 mb-lg-0">
                        <li className="nav-item">
                        <Link className="nav-link" to="/stu-card">Stu-Card</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link" to="/stu-table">Stu-Table</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link" to="/fac-card">Fac-Card</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link" to="/fac-table">Fac-Table</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link" to="/pro-card">Pro-Card</Link>
                        </li>
                        <li className="nav-item">
                        <Link className="nav-link" to="/pro-table">Pro-Table</Link>
                        </li>
                        
                        
                    </ul>
                    <form className="d-flex" role="search">
                        <input className="form-control me-2" type="search" placeholder="Search" aria-label="Search" />
                        <button className="btn btn-outline-success" type="submit">Search</button>
                    </form>
                    </div>
                </div>
                </nav>
        </>
    );
}

export default Header;