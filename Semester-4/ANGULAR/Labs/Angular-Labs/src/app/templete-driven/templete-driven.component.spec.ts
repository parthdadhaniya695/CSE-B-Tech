import { ComponentFixture, TestBed } from '@angular/core/testing';

import { TempleteDrivenComponent } from './templete-driven.component';

describe('TempleteDrivenComponent', () => {
  let component: TempleteDrivenComponent;
  let fixture: ComponentFixture<TempleteDrivenComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [TempleteDrivenComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(TempleteDrivenComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
