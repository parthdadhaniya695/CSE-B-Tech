import { Component } from '@angular/core';
import { RouterLink, RouterLinkActive, RouterOutlet } from '@angular/router';
import { ReactiveFormComponent } from "./reactive-form/reactive-form.component";
import { TempleteDrivenComponent } from "./templete-driven/templete-driven.component";

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, ReactiveFormComponent, TempleteDrivenComponent,RouterLink,RouterLinkActive],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Angular-Labs';
}
