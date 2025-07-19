import React from 'react'

function Job() {
    return (
        <>
            <div className="container">
                <div className="row">


                    <div className="col-md-4">
                        <h5>Fruits</h5>
                        <ul className="list-group">
                            <li className="list-group-item">Apple</li>
                            <li className="list-group-item">Banana</li>
                            <li className="list-group-item">Orange</li>
                        </ul>
                    </div>


                    <div className="col-md-4">
                        <h5>Vegetables</h5>
                        <ul className="list-group">
                            <li className="list-group-item">Carrot</li>
                            <li className="list-group-item">Broccoli</li>
                            <li className="list-group-item">Spinach</li>
                        </ul>
                    </div>


                    <div className="col-md-4">
                        <h5>Dairy</h5>
                        <ul className="list-group">
                            <li className="list-group-item">Milk</li>
                            <li className="list-group-item">Cheese</li>
                            <li className="list-group-item">Yogurt</li>
                        </ul>
                    </div>

                </div>
            </div>
        </>
    )
}

export default Job