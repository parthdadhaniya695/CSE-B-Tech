import { useState } from 'react'
import './App.css'
import FacultyCard from './pages/FacultyCard'
import StudentCard from './pages/StudentCard'
import StudentTable from './pages/StudentTable'
import FacultyTable from './pages/FacultyTable'
import ProductCard from './pages/ProductCard'
import ProductTable from './pages/ProductTable'

import { BrowserRouter, Route, Routes } from 'react-router-dom'
import Layout from './parts/Layout'
function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      {/* Props-Demo */}
      {/* <ParentComponent/> */}
      {/* Event-Handle */}
      {/* <EventHandlingExample/> */}
      {/* Conditional-Rendering */}
      {/* <Conditional_rendering/> */}
      {/* Lab-16 */}
      {/* Map Method */}
      {/* <Mapdemo/> */}
      
      <BrowserRouter>
        <Routes>
          <Route path='/' element={<Layout/>}>
            <Route path="/stu-card" element={<StudentCard/>}></Route>
            <Route path='/stu-table' element={<StudentTable/>}></Route>
            <Route path='/fac-card' element={<FacultyCard/>}></Route>
            <Route path='/fac-table' element={<FacultyTable/>}></Route>
            <Route path='/pro-card' element={<ProductCard/>}></Route>
            <Route path='/pro-table' element={<ProductTable/>}></Route>
          </Route>
        </Routes>
      </BrowserRouter>
      
    </>
  )
}

export default App
