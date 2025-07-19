import { NgIf } from '@angular/common';
import { Component, inject } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';

@Component({
  selector: 'app-reactive-form',
  imports: [ReactiveFormsModule,NgIf],
  templateUrl: './reactive-form.component.html',
  styleUrl: './reactive-form.component.css'
})
export class ReactiveFormComponent {
  // load From-Builder
  _fb = inject(FormBuilder);

  // Create form group with Form-Builder and add Validation
  userFrom:FormGroup = this._fb.group({
    username: ['', [Validators.required, Validators.maxLength(8)]],
    email: ['',[Validators.required, Validators.pattern("/^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$/")]],
    contactNo: ['',[Validators.required, Validators.pattern("[0-9]{10}")]],
    spi: ['',[Validators.required, Validators.min(0), Validators.max(10),Validators.pattern(/^\d+(\.\d{1,2})?$/)]],
  })

  addAgeControl(){
    this.userFrom.addControl('age',
      this._fb.control('', [Validators.required,Validators.min(18)]));
  }

  removeAgeControl(){
    this.userFrom.removeControl('age');
  }
}
