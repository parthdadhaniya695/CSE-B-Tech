import { CommonModule, NgFor } from '@angular/common';
import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,CommonModule,NgFor],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'resume-builder';

  stu:any={
    projects:[]
  }

  tempProject={}

  addData(e:any){
    this.stu={...this.stu,[e.target.name]:e.target.value}
  }

  formData(e:any){
    this.tempProject={...this.tempProject,[e.target.name]:e.target.value}
  }

  ProjectData(e:any){
    this.stu.projects.push(this.tempProject);
  }

}
