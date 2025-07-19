import { NgIf } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-templete-driven',
  imports: [FormsModule,NgIf],
  templateUrl: './templete-driven.component.html',
  styleUrl: './templete-driven.component.css'
})
export class TempleteDrivenComponent {
  user = {
    username: '',
    email: '',
    age: 0,
    contactNo: 0,
    spi: 0.0
  }
}
