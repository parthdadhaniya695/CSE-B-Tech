import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
// import ProductCRUD from './ProductCRUD'
import FacultyCRUD from './FacultyCRUD'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      {/* <ProductCRUD/> */}
      <FacultyCRUD/>
    </>
  )
}

export default App
