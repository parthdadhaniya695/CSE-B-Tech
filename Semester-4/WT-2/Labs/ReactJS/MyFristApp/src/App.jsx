import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
import './Cal.css'
import Counter from './UseState'
import InputLogger from './InputChange'
import UseEffectDemo from './useEffectDemo'
import Calculator from './Calculator'

function App() {
  const [count, setCount] = useState(0)

  return (
    <>
      {/* <Counter/> */}
      {/* <InputLogger/> */}
      {/* <UseEffectDemo/> */}
      <Calculator/>
    </>
  )
}

export default App
