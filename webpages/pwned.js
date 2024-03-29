import React from 'react';
import './pwned.css';
import img from './img.jpeg'

function pwned() {
  return (
    <div className="hacked">
      <img src={img} alt="pwned" className="hacked-image" />
      <h1>School's Out</h1>
      <p>Your website has been pwned</p>
      <p>Sincerely...Red Team</p>
    </div>
  );
}

export default pwned;
