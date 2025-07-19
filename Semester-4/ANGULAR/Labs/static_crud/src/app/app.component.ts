import { Component } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { OnedComponent } from "./oned/oned.component";

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, OnedComponent],
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'static_crud';
}
