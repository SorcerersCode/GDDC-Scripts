import './App.css';
import { BrowserRouter as Router, Route, Routes } from "react-router-dom";
import Pwned from './pwned';

function App() {
  return (
    <div>
      <Router>
        <Routes>
          <Route path="" element={<Pwned/>}></Route>
        </Routes>
      </Router>
    </div>
  );
}

export default App;
